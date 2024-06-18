inp = int(input("x 저장 값을 입력하시오: "))

result = False

if (inp >= 10) :
    result = (inp % 10) == int((inp / 10))
else :
    result = True

print(f"출력값은 {result} 입니다.")