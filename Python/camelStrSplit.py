#!/bin/sh/env python

import sys

class camelStr:
    _myStr = ""
    _ll = []
    _ul = []
    _nl = []
    _space = ord(" ")

    def __init__(self):
        # print("Creating object with "+self._myStr)
        self._ll = [n for n in range(ord("a"), ord("z"))]
        self._ul = [n for n in range(ord("A"), ord("Z"))]
        self._nl = [n for n in range(ord("0"), ord("9"))]

    def setStr(self, strVal = ""):
        self._myStr = strVal

    """
    validate function validates if the characters in the string are alphanumeric or are whitespaces. If not
    function returns False.
    *currently not working for special characters
    """
    def validate(self) -> bool:
        for i in range(len(self._myStr)):
            tStr = self._myStr[i]
            if tStr not in [self._ul, self._ll, self._nl, self._space]:
                return False
        return True

    """
    findNxtIndLen function takes in a string truncated to the last returned index of split functionality
    and returns the next index in the string where the string needs to split up.
    """
    def findNxtIndLen(self, ins: str) -> int:
        tl = 0
        for j in range(len(ins)):
            if j == 0:
                tl += 1
                continue
            tpStr = ord(ins[j-1])
            tStr = ord(ins[j])

            if tStr in self._ul:
                if tpStr in self._ul:
                    tl += 1
                else:
                    return tl
            if tStr in self._ll:
                if (tpStr in self._ll) or (tpStr in self._ul):
                    tl += 1
                else:
                    return tl
            if tStr in self._nl:
                if tpStr in self._nl:
                    tl += 1
                else:
                    return tl
            if tStr == self._space:
                if tpStr == self._space:
                    tl += 1
                else:
                    return tl
        return tl

    def Split(self) -> list:
        if self.validate():
            return [self._myStr]
        ans = []
        i = 0
        while True:
            #print("Sending String : "+self._myStr[i:])
            l = self.findNxtIndLen(self._myStr[i:])
            #print("length = "+str(l)+"; Appending List "+self._myStr[i:i+l])
            ans.append(self._myStr[i:i+l])
            i = i+l
            if i >= len(self._myStr):
                break
        return ans

def printUsage():
    print("Usage: python camelStrSplit.py <string-to-split>")

if __name__ == "__main__":
    if len(sys.argv) == 1:
        printUsage()
        exit()
    cs = camelStr()
    cs.setStr(sys.argv[1])
    splitList = cs.Split()
    print(splitList)

"""Example Strings
"myStr123"
"my  123"
r"0xb\xe2\xd1"
"""
