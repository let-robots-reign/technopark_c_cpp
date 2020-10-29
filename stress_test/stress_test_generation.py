from random import randint, uniform

RECORDS_NUMBER = 10 ** 7
# grade can't be in (0; 1)
INVALID_GRADE_LOWER_BOUND = 0
INVALID_GRADE_UPPER_BOUND = 1

with open("stress_test.txt", "w", encoding="utf-8") as stress_file:
    stress_file.write(f"{RECORDS_NUMBER}\n")
    comment_id = 0
    for i in range(RECORDS_NUMBER):
        grade = round(uniform(0, 5), 3)
        while INVALID_GRADE_LOWER_BOUND < grade < INVALID_GRADE_UPPER_BOUND:
            grade = round(uniform(0, 5), 3)
        if not grade:
            votes = 0
        else:
            votes = randint(1, 2 ** 30)

        stress_file.write(f"{comment_id} {grade} {votes}\n")
        comment_id += 1
