
class Solution:
    def lcmTriplets(self,N):

        if N<3:

            return N

        if N%2==0:

            if N%3==0:

                return ((N-2)*(N-1)*(N-3))

            else:

                return ((N-3)*(N-1)*(N))

        return ((N-2)*(N-1)*(N))
