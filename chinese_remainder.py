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


a = [2, 3, 9]
m = [3, 7, 10]

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
print(soma, lcm, soma % lcm)
