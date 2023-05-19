
range1 = [[2,6],[5,7]]

queries = [5,8]

s = set()



for i in range1:
     max = -111110
     min = 100000
     for j in i:
          if j<min:
               min = j
          if j>max:
               max = j
     for x in range(min,max+1):
          s.add(x)


l = list(s)
l.sort()
n = len(l)

for i in queries:
     if i>n:
          print(-1)
     else:
          print(l[i-1])



# print(l)



















