# 10-6
# print("Give me two numbers, and I'll add them.")
# num1 = input("Number1: ")
# num2 = input("Number2: ")
# try:
#     num1 = int(num1)
#     num2 = int(num2)
# except ValueError:
#     print("Give me two numbers, tks.")
# else:
#     print(num1 + num2)

# 10-7
# filelist = ['Practice10_3/cats.txt', 'Practice10_3/dogs.txt', 'human.txt']
# out = ''
# for file in filelist:
#     try:
#         with open(file) as current_file:
#             outs = current_file.readlines()
#             for out in outs:
#                 print(out.rstrip().title())
#             print('\n')
#     except FileNotFoundError:
#         print(file + ' is not found.')

# 10-8
# filelist = ['Practice10_3/cats.txt', 'Practice10_3/dogs.txt', 'human.txt']
# out = ''
# for file in filelist:
#     try:
#         with open(file) as current_file:
#             outs = current_file.readlines()
#             for out in outs:
#                 print(out.rstrip().title())
#             print('\n')
#     except FileNotFoundError:
#         pass

# 10-9
booklist = [
    'Practice10_3/Dracula.txt', 
    'Practice10_3/TheWonderfulWizardOfOz.txt', 
    'Practice10_3/WarAndPiece.txt'
    ]
for book in booklist:
    try:
        with open(book) as file:
            line = file.read()
            line = line.lower()
            print(line.count('i'))
    except FileNotFoundError:
        print("File not found.")