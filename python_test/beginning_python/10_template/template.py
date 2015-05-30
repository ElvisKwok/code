#!/usr/bin/env python
# coding: utf-8 

import fileinput, re

# 匹配括号里的字段
field_pat = re.compile(r'\[(.+?)\]')

# 变量收集
scope = {}

# 用于re.sub中
def replacement(match):
    code = match.group(1)
    try:
        # 如果字段可以求值
        return str(eval(code, scope))
    except SyntaxError:
        # 否则执行“相同作用域”内的赋值语句
        exec code in scope
        # 返回空字符串
        return ""

# 所有文本获取到一个字符串
lines = []
for line in fileinput.input():
    lines.append(line)
text = ''.join(lines)

# 将field模式所有匹配项都替换掉
print field_pat.sub(replacement, text)
