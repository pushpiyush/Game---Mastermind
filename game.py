# game constant
KEY_LENGTH = 4
ALLOWED_GUESS = 12

history = []


# check if the key has exactly 4 digits and each digits are unique
def valid_key(key):
    buffer = str(key)

    if (len(buffer)) != KEY_LENGTH:
        print("****must have length of 4, try again")
        print()
        return False
    
    for i in range(len(buffer)):
        for j in range(i+1, len(buffer)):
            if buffer[i] == buffer[j]:
                print("****no repeated digits, try again")
                print()
                return False

    return True


# add current guess into history list and print all guesses
def update_history(key, guess, i):
    buffer = str(key)
    buffer2 = str(guess)
    exist, position = 0, 0

    for i in range(KEY_LENGTH):
        for j in range(KEY_LENGTH):
            if buffer[i] == buffer2[j]:
                exist += 1
                if i == j:
                    position += 1
    
    history.append({"guess": guess, "exist": exist, "position": position})

    for i in range(len(history)):
        h = history[i]
        print(f"{h["guess"]} : exist:{h["exist"]}, position:{h["position"]}")


# get the key as user's input 
while True:
    try:
        key = int(input("Key: "))
    except valueError:
        print("****contains non-number, try again")
        print()
        continue
    
    if valid_key(key):
        break

# get the guesses and check them
for i in range(ALLOWED_GUESS):
    # get guess as user's input
    while True:
        try:
            guess = int(input("Guess: "))
        except:
            print("****contains non-number, try again")
            print()
            continue
        
        if valid_key(guess):
            break
    
    update_history(key, guess, i)

    # if the guess is correct
    if guess == key:
        print("You guessed the key:", key)
        print("It took you {} guesses".format(i+1))
        break
    elif i == (ALLOWED_GUESS - 1):
        print("You have made all {} guesses and could not guess the key.".format(ALLOWED_GUESS))
        print("The key is:", key)
    
    print()