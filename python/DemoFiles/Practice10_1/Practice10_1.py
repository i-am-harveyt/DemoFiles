# 10-1
# out = ''

# with open (
#     '/Users/tonghaoting/Desktop/Programming practice/python/DemoFiles/Practice10_1/InPythonILearn.txt'
#     ) as file:
#     lines = file.readlines()
#     for line in file.readlines():
#         print(line.rstrip())
#         out += line.rstrip() + '\n'

# print('\n'+out)
# for line in lines:
#     print(line.rstrip())

# 10-2
lines = ''
with open (
    '/Users/tonghaoting/Desktop/Programming practice/python/DemoFiles/Practice10_1/InPythonILearn.txt'
    ) as file:
    lines = file.readlines()
for line in lines:
    print(line.replace('Python', 'Java').rstrip())
