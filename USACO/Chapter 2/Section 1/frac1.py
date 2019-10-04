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
# rooms=[list(map(int,line.strip().split(' '))) for line in fin.readlines()]
def getGcd(a,b):
#     print("GETGCD",a,b)
    q,r=divmod(a,b)
#     print("Q=",q,"R=",r,"B",b)
    if r == 0:
        return b
    else :
        return getGcd(b,r)
fracList=[]
fracList.append("0/1")
for den in range(1,N+1):
    for num in range(1,N+1):
        if den>=num:
            gcd=getGcd(den,num)
#             print(num,den,gcd)
            frac=f"{int(num/gcd)}/{int(den/gcd)}"
#                 print("A",frac)
            if not frac in fracList:
                fracList.append(frac)
fracList.sort(key=getKey)

with open('frac1.out','w') as fout:
    for e in fracList:
        fout.write(e+'\n')