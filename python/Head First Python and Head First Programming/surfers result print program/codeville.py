scores = {}
results_f = open("results.txt")

for line in results_f:
    (name,score) = line.split()
    scores[score] = name

results_f.close()
print("The Top Scores were:")
for each_score in sorted(scores.keys(),reverse = True):
    print("Surfer " + scores[each_score] + ' Scored ' + each_score)
