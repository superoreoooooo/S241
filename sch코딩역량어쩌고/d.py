User_times = [20,40,65,110]

T = 30

def solution(User_times, T) :
    maxTime = 0
    for i in range(0, len(User_times), 1) :
        if (User_times[i] % T == 0) :
            continue
        remp1 = int(User_times[i] / T) + 1
        if ((remp1 * T) - User_times[i] > maxTime) :
            maxTime = (remp1 * T) - User_times[i]

    return maxTime

print(solution(User_times, T))