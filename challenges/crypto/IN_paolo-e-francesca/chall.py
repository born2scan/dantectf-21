#TODO: switch to getSecurePrime
from Crypto.Util.number import getPrime

FLAG = b"[REDACTED]"

# thanks to Rivest, Shamir and Adleman
m = int.from_bytes(FLAG,'big')
p = getPrime(333)
q = 13555951496777604631139270237917994748488574297776756734164338349749523288010729072351577528529826741
n = p*q
e = 65537
d = pow(e,-1,(p-1)*(q-1))
c = pow(m,e,n)

print("n =",n)
print("e =",e)
print("c =",c)
