# ANALYSIS
"""
ID: xggc1
LANG: PYTHON3
PROG: frac1
"""
def getKey(s):
    num,den=map(int,s.strip().split("/"))
    return num/den

fin = open('frac1.in','r')
N = int(fin.readline().strip())
def getGcd(a,b):
    q,r=divmod(a,b)
    if r == 0:
        if b==1:
            return 1
        else:
            return 0
    else :
        return getGcd(b,r)
fracList=[]
fracList.append("0/1")
for den in range(1,N+1):
    for num in range(1,den+1):
        if getGcd(den,num):
            frac=f"{num}/{den}"
            if not frac in fracList:
                fracList.append(frac)
                
fracList.sort(key=getKey)

with open('frac1.out','w') as fout:
    for e in fracList:
        fout.write(e+'\n')