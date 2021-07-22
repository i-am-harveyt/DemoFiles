# 10-3
# ask_username = "What's your username? "
# greeting = 'Hello, '
# user_file_path = 'Practice10_2/guest.txt'
# with open(user_file_path, 'a') as file:
#     username = input(ask_username)
#     file.write(username.lower() + '\n')
#     print(greeting + username.title() + '!\n')

# 10-4
# ask_username = "What's your username? "
# greeting = 'Hello, '
# user_file_path = 'Practice10_2/guest.txt'
# username = ''
# with open(user_file_path, 'a') as file:
#     while username != quit:
#         username = input(ask_username)
#         if username == 'quit':
#             break
#         file.write(username.lower() + '\n')
#         print(greeting + username.title() + '!\n')
#     print("\nEnd while loop.")
# print("File closed.")

# 10-5
ask_username = "What's your username? "
ask_reason = "Why do you like programming? "
greeting = 'Hello, '
user_file_path = 'Practice10_2/guest.txt'
reason_file_path = 'Practice10_2/reason.txt'
username = ''
reason = ''
with open(user_file_path, 'a') as user_file:
    with open(reason_file_path, 'a') as reason_file:
        while username != quit:
            print(ask_username + 'Answer "quit" to quit. ')
            username = input()
            if username == 'quit':
                break
            user_file.write(username.lower() + '\n')
            print(greeting + username.title() + '!\n')
            while reason != 'none':
                print(ask_reason + 'Answer "none" to quit. ')
                reason = input()
                if reason == 'none':
                    reason = ''
                    print('\n')
                    break
                reason_file.write(reason + '\n')