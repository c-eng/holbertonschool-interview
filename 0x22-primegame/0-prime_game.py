#!/usr/bin/python3
"""isWinner function
"""


def isWinner(x, nums):
    """isWinner
    """
    maria = 0
    ben = 0
    numlen = len(nums)
    for i in range(x):
        ren = i if i < numlen - 1 else numlen - 1
        if gameSet(nums[ren]) == 1:
            maria += 1
        else:
            ben += 1
    if maria > ben:
        return "Maria"
    elif ben > maria:
        return "Ben"
    else:
        return "None"


def gameSet(n):
    """gameSet
    """
    primes = 0
    for i in range(n + 1):
        if isPrime(i):
            primes += 1
    return primes % 2


def isPrime(num):
    """isPrime
    """
    if num == 1:
        return False
    if num == 2:
        return True
    for i in range(2, num + 1):
        if (num % i) == 0:
            break
        else:
            return True
    return False
