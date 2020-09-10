m,d,y = input().split('/')
if(len(m) == 1):
    m = "0"+str(m)
if(len(d) == 1):
    d = "0"+str(d)
print("%s%s%s" % (y,m,d))
