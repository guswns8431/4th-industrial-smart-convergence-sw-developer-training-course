a = 10
b = 20
c = a + b

print(a, b, c)

# 입력 값을 변수에 저장하기
x = input('문자열을 입력하세요 : ')
print(x)

# 입력 값을 정수로 변환하기
a = input('첫 번째 숫자를 입력하세요 : ')
b = input('두 번째 숫자를 입력하세요 : ')
print(a+b)

a = int(input('첫 번째 숫자를 입력하세요 : '))
b = int(input('두 번째 숫자를 입력하세요 : '))
print(a+b)

# 입력 값을 변수 두 개에 저장하기
a, b = input('문자열 두 개를 입력하세요 : ').split()

print(a)
print(b)

# 입력 밧을 정수로 변환하기
a, b = input('숫자 두 개를 입력하세요 : ').split()
a = int(a)
b = int(b)
print(a+b)
print(int(a)+int(b))

# map을 사용하여 정수로 변환하기
c, d = map(int, input('숫자 두 개를 입력하세요: ').split())
print(c+d)
