"""Based on a script from redddit-analysis, but modified to fit looking at pure textfiles instead.
Re-written such that I learn again by doing the dictionaries myself."""

import os
import sys
reload(sys)
sys.setdefaultencoding('utf-8')

from collections import defaultdict
from nltk import word_tokenize
import glob
from wordcloud import WordCloud

#Setup current folder and subfolder with the textfiles
CURRENT_FOLDER = os.path.dirname(__file__)
try:
    TEXT_FOLDER = str(sys.argv[1])
    print "Text folder = ", TEXT_FOLDER
except:
    print "No text folder name provided, uses test-folder"
    TEXT_FOLDER = "test-folder";
    print "Text folder = ", TEXT_FOLDER

#Load a list of common words to ignore
all_words = defaultdict(int)
popular_words = defaultdict(int)
COMMON_WORDS = set()
with open("common-words.txt", "r") as in_file:
    for line in in_file:
        COMMON_WORDS.add(line.strip().lower())

#Function for parsing a textfile
def parse_text(textfile):
    textfile = textfile.lower();
    textfile.split()
    for token in word_tokenize(textfile):
        all_words[token] += 1
        if token not in COMMON_WORDS:
            popular_words[token] += 1

#Iterate between all textfiles in the subfolder
for filename in glob.glob(os.path.join(CURRENT_FOLDER, TEXT_FOLDER, "*.txt")):
    current_text = open(filename,"r");
    parse_text(current_text.read())
    print "Parsing ", filename
    
print "Combining singular and multiple forms of the words"    
#Add singular and multiple form of the same words
for word in list(popular_words.keys()):
        count = popular_words[word]

        if word.endswith("s"):
            # if the singular form of the word was used/exist
            singular = word[:-1]
            if popular_words[singular] > 0:
                # combine the count into the most-used form of the word
                if popular_words[singular] > count:
                    popular_words[singular] += popular_words[word]
                    del popular_words[word]
                else:
                    popular_words[word] += popular_words[singular]
                    del popular_words[singular]

        if word.endswith("ies"):
            # if the singular form of the word was used/exist
            singular = "{0}y".format(word[:-3])
            if popular_words[singular] > 0:
                # combine the count into the most-used form of the word
                if popular_words[singular] > count:
                    popular_words[singular] += popular_words[word]
                    del popular_words[word]
                else:
                    popular_words[word] += popular_words[singular]
                    del popular_words[singular]

print "Printing the result to ", "result.csv"
result_file = open("result.csv","w")
lower_limit = 20;
for word in sorted(popular_words, key=popular_words.get, reverse=True):
        if popular_words[word] > lower_limit:
            priority = True

            # don't print the word if it's just a number
            if word.isdigit():
                priority = False
                
            #Print to the .csv file
            if priority:
                out_text = unicode("{0}:{1}\n".format(word, popular_words[word]))
                result_file.write(out_text)
result_file.close()