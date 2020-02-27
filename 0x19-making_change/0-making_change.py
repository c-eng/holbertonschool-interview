#!/usr/bin/python3
"""
Given a pile of coins of different values, determine the fewest number of coins
needed to meet a given amount.
"""


def makeChange(coins, total):
    """
    change making function
    """
    if total < 1:
        return -1
    coins.sort()
    coins.reverse()
    "or use list.length"
    change = 0
    for coin in coins:
        temp = total // coin
        change += temp
        total -= (temp * coin)
    if total > 0:
        return -1
    return change
