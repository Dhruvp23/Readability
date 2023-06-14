# TODO
from cs50 import get_string


def main():
    # input from user (text to be read)
    usertext = get_string("Text: ")
    length = len(usertext)  # total length of usertext

    # letters count
    letter = 0  # letters counters
    for i in range(length):
        if usertext[i].isalpha() == True:
            letter = letter + 1

    # word count
    word = 1  # word counters
    for i in range(length):
        if usertext[i].isspace() == True:
            word = word + 1

    # sentences count

    Spchar = length - usertext.count("?") - \
        usertext.count(".") - usertext.count("!")
    sentences = length - Spchar

    L = letter / word * 100
    S = sentences / word * 100

    index = round(0.0588 * L - 0.296 * S - 15.8)

    if index >= 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print("Grade",index)
    print()


main()
