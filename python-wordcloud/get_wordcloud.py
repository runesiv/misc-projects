import os
import csv
from wordcloud import WordCloud


filename = "result.csv"
word_limit = 50;

imported_dictionary = dict(filter(None, csv.reader(open(filename), delimiter = ":"))); 
for word in list(imported_dictionary.keys()):
    imported_dictionary[word] = int(imported_dictionary[word])

wordcloud = WordCloud(max_words = word_limit).generate_from_frequencies(imported_dictionary)

# Display the generated image:
# the matplotlib way:
import matplotlib.pyplot as plt
plt.imshow(wordcloud, interpolation='bilinear')
plt.axis("off")

# lower max_font_size
wordcloud = WordCloud(max_font_size=40, max_words = word_limit).generate_from_frequencies(imported_dictionary)
plt.figure()
plt.imshow(wordcloud, interpolation="bilinear")
plt.axis("off")
plt.show()