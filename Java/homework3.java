import java.util.Scanner;

public class homework3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        //input team
        System.out.println("first team");
        String team1Str = scanner.nextLine();
        System.out.println("first team's effect");
        String effect1Str = scanner.nextLine();

        System.out.println("second team");
        String team2Str = scanner.nextLine();
        System.out.println("second team's effect");
        String effect2Str = scanner.nextLine();

        String[] team1Arr = team1Str.split("-");
        String[] effect1Arr = effect1Str.split("-");
        String[] team2Arr = team2Str.split("-");
        String[] effect2Arr = effect2Str.split("-");

        TeamData team1 = new TeamData(team1Arr, Integer.parseInt(effect1Arr[0]), Integer.parseInt(effect1Arr[1]));
        TeamData team2 = new TeamData(team2Arr, Integer.parseInt(effect2Arr[0]), Integer.parseInt(effect2Arr[1]));

        int time = 0;
        int distance1 = 0, distance2 = 0;
        int team1Now = 0, team2Now = 0;

        while (true) {

            //if (time % 5 == 0) {
            if(true){
                String team1Effect, team2Effect;
                if (team1.isFreeze && team1.isGravitize) {
                    team1Effect = "freezed and gravitized";
                } else if (team1.isFreeze) {
                    team1Effect = "freezed";
                } else if (team1.isGravitize) {
                    team1Effect = "gravitized";
                } else {
                    team1Effect = "no effect";
                }
                if (team2.isFreeze && team2.isGravitize) {
                    team2Effect = "freezed and gravitized";
                } else if (team2.isFreeze) {
                    team2Effect = "freezed";
                } else if (team2.isGravitize) {
                    team2Effect = "gravitized";
                } else {
                    team2Effect = "no effect";
                }
                System.out.println(String.format("now time: %d", time));
                System.out.println(String.format("team1 now: number %d, type: %s, effect: %s, distance: %d",
                        team1Now + 1, team1.player[team1Now], team1Effect, distance1));
                System.out.println(String.format("team2 now: number %d, type: %s, effect: %s, distance: %d",
                        team2Now + 1, team2.player[team2Now], team2Effect, distance2));
                
                if (time % 5 == 0) {
                    while (true) {
                        System.out.println(String.format(
                                "team1 you have %d freeze and %d gravitize, please choose your effect to use",
                                team1.freeze, team1.gravatize));
                        String[] team1Use = scanner.nextLine().split("-");
                        if (Integer.parseInt(team1Use[0]) > 1 || Integer.parseInt(team1Use[0]) > team1.freeze
                                || Integer.parseInt(team1Use[1]) > team1.gravatize) {
                            System.out.println("error");
                            continue;
                        }

                        if (Integer.parseInt(team1Use[0]) == 1) {
                            if (team2.player[team2Now].equals("str")) {
                                team2.freezeSec = 5;
                            } else {
                                team2.freezeSec = 3;
                            }
                            team2.isFreeze = true;
                            team1.freeze--;
                        }

                        if (Integer.parseInt(team1Use[1]) == 1) {
                            if (team2.player[team2Now].equals("dex")) {
                                team2.isGravitize = true;
                            }
                            team1.gravatize--;
                        }

                        break;
                    }

                    while (true) {
                        System.out.println(String.format(
                                "team2 you have %d freeze and %d gravitize, please choose your effect to use",
                                team2.freeze, team2.gravatize));
                        String[] team2Use = scanner.nextLine().split("-");
                        if (Integer.parseInt(team2Use[0]) > 1 || Integer.parseInt(team2Use[0]) > team2.freeze
                                || Integer.parseInt(team2Use[1]) > team2.gravatize) {
                            System.out.println("error");
                            continue;
                        }

                        if (Integer.parseInt(team2Use[0]) == 1) {
                            if (team1.player[team1Now].equals("str")) {
                                team1.freezeSec = 5;
                            } else {
                                team1.freezeSec = 3;
                            }
                            team1.isFreeze = true;
                            team2.freeze--;
                        }

                        if (Integer.parseInt(team2Use[1]) == 1) {
                            if (team1.player[team1Now].equals("dex")) {
                                team1.isGravitize = true;
                            }
                            team2.gravatize--;
                        }

                        break;
                    }
                }
            }

            //team1
            if (team1.player[team1Now].equals("dex")) {
                if (team1.isFreeze) {
                    team1.freezeSec--;
                    if (team1.freezeSec == 0) {
                        team1.isFreeze = false;
                    }
                } else {
                    if (team1.isGravitize) {
                        distance1 += 10;
                    } else {
                        distance1 += 20;
                    }
                    if (distance1 >= 100) {
                        team1 = resetData(team1);
                        distance1 = 0;
                        team1Now++;
                        if (team1Now == 5) {
                            System.out.println("team1 won");
                            break;
                        }
                    }
                }
            } else {
                if (team1.isFreeze) {
                    team1.freezeSec--;
                    if (team1.freezeSec == 0) {
                        team1.isFreeze = false;
                    }
                } else {
                    distance1 += 10;
                    if (distance1 >= 100) {
                        team1 = resetData(team1);
                        distance1 = 0;
                        team1Now++;
                        if (team1Now == 5) {
                            System.out.println("team1 won");
                            break;
                        }
                    }
                }
            }

            //team2
            if (team2.player[team2Now].equals("dex")) {
                if (team2.isFreeze) {
                    team2.freezeSec--;
                    if (team2.freezeSec == 0) {
                        team2.isFreeze = false;
                    }
                } else {
                    if (team2.isGravitize) {
                        distance2 += 10;
                    } else {
                        distance2 += 20;
                    }
                    if (distance2 >= 100) {
                        team2 = resetData(team2);
                        distance2 = 0;
                        team2Now++;
                        if (team2Now == 5) {
                            System.out.println("team2 won");
                            break;
                        }
                    }
                }
            } else {
                if (team2.isFreeze) {
                    team2.freezeSec--;
                    if (team2.freezeSec == 0) {
                        team2.isFreeze = false;
                    }
                } else {
                    distance2 += 10;
                    if (distance2 >= 100) {
                        team2 = resetData(team2);
                        distance2 = 0;
                        team2Now++;
                        if (team2Now == 5) {
                            System.out.println("team2 won");
                            break;
                        }
                    }
                }
            }

            time++;
        }
        scanner.close();
    }
    
    public static TeamData resetData(TeamData t) {
        t.isFreeze = false;
        t.freezeSec = 0;
        t.isGravitize = false;
        return t;
    }
    
    public static class TeamData {
        String[] player;
        int freeze;
        int gravatize;
        Boolean isFreeze = false;
        int freezeSec = 0;
        Boolean isGravitize = false;

        TeamData(String[] p, int f, int g) {
            this.freeze = f;
            this.gravatize = g;
            this.player = p;
        }
    }
}