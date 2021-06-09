import math
import matplotlib.pyplot as plt
import gym
import numpy as np

env = gym.make('CartPole-v1')

get_epsilon = lambda i: max(0.01, min(1.0, 1.0 - math.log10((i + 1) / 25)))  # epsilon-greedy; 隨時間遞減
get_lr = lambda i: max(0.01, min(0.5, 1.0 - math.log10((i + 1) / 25)))  # learning rate; 隨時間遞減
gamma = 0.99  # reward discount factor

# 準備 Q table
# Environment 中各個 feature 的 bucket 分配數量
# 1 代表任何值皆表同一 state，也就是這個 feature 其實不重要
n_buckets = (1, 1, 6, 3)

# Action 數量
n_actions = env.action_space.n

# State 範圍
state_bounds = list(zip(env.observation_space.low, env.observation_space.high))
state_bounds[1] = [-0.5, 0.5]
state_bounds[3] = [-math.radians(50), math.radians(50)]

q_table = np.zeros(n_buckets + (n_actions,))


def choose_action(state, q_table, action_space, epsilon):
    if np.random.random_sample() < epsilon:
        return action_space.sample()
    else:
        return np.argmax(q_table[state])


def get_state(observation, n_buckets, state_bounds):
    stat = [0] * len(observation)
    for i, s in enumerate(observation):  # 每個 feature 有不同的分配
        l, u = state_bounds[i][0], state_bounds[i][1]  # 每個 feature 值的範圍上下限
        if s <= l:  # 低於下限，分配為 0
            stat[i] = 0
        elif s >= u:  # 高於上限，分配為最大值
            stat[i] = n_buckets[i] - 1
        else:  # 範圍內，依比例分配
            stat[i] = int(((s - l) / (u - l)) * n_buckets[i])
    return tuple(stat)


plt_totalReward = []
plt_epsilon = []
plt_timesteps = []
plt_episodes = []

for i_episode in range(200):
    epsilon = get_epsilon(i_episode)
    lr = get_lr(i_episode)

    observation = env.reset()
    rewards = 0
    state = get_state(observation, n_buckets, state_bounds)  # 將連續值轉成離散
    for t in range(250):
        env.render()

        action = choose_action(state, q_table, env.action_space, epsilon)
        observation, reward, done, info = env.step(action)

        rewards += reward

        next_state = get_state(observation, n_buckets, state_bounds)
        q_next_max = np.amax(q_table[next_state])  # 進入下一個 state 後，預期得到最大總 reward
        q_table[state + (action,)] += lr * (reward + gamma * q_next_max - q_table[state + (action,)])  # 就是那個公式

        state = next_state
        if done:
            print('Episode finished after {} timesteps, total rewards {}'.format(t + 1, rewards))
            break
    plt_epsilon.append(epsilon*50)
    plt_totalReward.append(rewards)
    plt_episodes.append(i_episode)

plt.plot(plt_episodes, plt_epsilon)
plt.plot(plt_episodes, plt_totalReward)
plt.title("Q-learning CartPole")
plt.xlabel("episodes")
plt.show()
env.close()
