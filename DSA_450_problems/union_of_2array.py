class Solution:    
    #Function to return the count of number of elements in union of two arrays.
    def doUnion(self,a,n,b,m):
       a =set(a)
       b = set(b)
       return (len(a|b))