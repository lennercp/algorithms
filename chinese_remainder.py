def gcd_extended(a, b):
    x = 1
    y = 0
    x1 = 0
    y1 = 1

    while b != 0:
        q = a // b
        x, x1 = x1, x - q * x1
        y, y1 = y1, y - q * y1
        a, b = b, a - q * b

    return [a, x, y]


print("Digite as congruencias na forma c a m, onde c é o coeficiente do x, a é o numero congruente e m o modulo, para parar digite 0")

a= []
m = []
while True:
    inp = list(map(int,input().split()))
    if(inp[0] == 0): break
    aux, x, y = gcd_extended(inp[0], inp[2])
    inv = max(1, (inp[2] + x) % inp[2])
    a.append(inp[1] * inv % inp[2])
    m.append(inp[2])
    
# lcm of all elements in m
lcm = m[0]
for i in range(1, len(m)):
    lcm = lcm * m[i] / gcd_extended(lcm, m[i])[0]

m_zao = []
for i in range(len(m)):
    m_zao.append(int(lcm / m[i]))

m_inv = []
for i in range(len(m)):
    aux, x, y = gcd_extended(m[i], m_zao[i])
    # modular inverse
    m_inv.append((m[i] + y) % m[i])

# a1*M1*(M1**-1) + a2*M2*(M2**-1) + a3*M3*(M1**-3) mod lcm
soma = 0
for i in range(len(m)):
    soma += a[i] * m_zao[i] * m_inv[i]
print("a = ", a)
print("M = ", m_zao)
print("Y = ", m_inv)
print(soma, " = mod", int(lcm))
print(int(soma%lcm), " = mod", int(lcm))
