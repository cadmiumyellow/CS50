# Program to assess text readability level as per Coleman-Liau formula

from cs50 import get_string

# Taking text input from user
text = get_string("Text: ")

# Counting letters, words and sentences
letters = 0
words = 1
sentences = 0

for x in text:
    # Counting letters
    if x.isalpha() is True:
        letters += 1

    # Counting words
    elif x.isspace() is True:
        words += 1

    # Counting sentences
    elif x in [".", "!", "?"]:
        sentences += 1

# Counting average number of letters per 100 words in the text
av_letters = letters * 100 / words

# Counting average number of sentences per 100 words in the text
av_sentences = sentences * 100 / words

# Calculating text readability Grade as per Coleman-Liau formula
grade = round((0.0588 * av_letters) - (0.296 * av_sentences) - 15.8)

# Printing out text's readability grade as per specification
if grade < 1:
    print("Before Grade 1")
elif grade > 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")