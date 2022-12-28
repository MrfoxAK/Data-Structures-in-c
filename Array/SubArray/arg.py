#def f1(a,b,c,d):
 #   print(a,b,c,d)
#f1("AK","SOUROV","DEB","AK2")    

def f1(normal,*b):
    print(normal)
    for item in b:
        print(item)
a = ["AK","SOUROV","DEB","AK2","AK25"] 
normal = "AK1"   
f1(normal,*a)    

"""def f2(*a):
    for item in a:
        print(item)
v1 = ["AK","sa"]    
f2(*v1)"""