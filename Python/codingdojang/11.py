#시퀀스 자료형의 공통 기능 사용하기
#특정 값이 있는지 확인하기
a = [0,10,20,30,40,50]
print(30 in a)
print(100 not in a)
print('P' in 'Hello, Python')

#시퀀스 객체 연결하기
a = [1,2,3,4]
b = [5,6,7,8,9]
print(a+b)
print(list(range(0,10))+list(range(10,20)))
print("hello" + "world")

#시퀀스 객체 반복하기
print([0,10,20,30] * 3)
print("hello" * 3)

#리스트와 튜플의 요소 개수 구하기
len(a)

#인덱스 사용하기
print(a[0])
print(a[-4])

#del로 요소 삭제하기
del a[2]

#슬라이스 사용하기 [시작인덱스:끝인덱스:인덱스증가폭]
a[0:4]
a[1:2]
a[4:-1]
a[2:8:3]
a[:7]
a[7:]
