import random
import subprocess

a = [2, 1, 3, 6, 5, 8]
b = []
res = sorted(a)

subprocess.run("make")

output = subprocess.run(["./push_swap", " ".join(str(i) for i in a)], stdout=subprocess.PIPE)
output_str = output.stdout.decode()
print("Output >\n```\n", output_str, "\n```", sep="")

for line in output_str.split("\n"):
	print("line >", line)

	if line == "sa" or line == "ss":
		if len(a) > 1:
			a[1::-1] = a[:2]
	if line == "sb" or line == "ss":
		if len(b) > 1:
			b[1::-1] = b[:2]

	if line == "pa":
		if len(b) > 0:
			a = [b.pop(0)] + a
	if line == "pb":
		if len(a) > 0:
			b = [a.pop(0)] + b

	if line == "ra" or line == "rr":
		if len(a) > 0:
			t = a.copy()
			a = [t[i+1] for i in range(len(t) - 1)].append(t[0])
	if line == "rb" or line == "rr":
		if len(b) > 0:
			t = b.copy()
			b = [t[i+1] for i in range(len(t) - 1)].append(t[0])

	if line == "rra" or line == "rrr":
		if len(a) > 0:
			t = a.copy()
			a = [t[-1]].append([t[i-1] for i in range(1, len(t))])
	if line == "rrb" or line == "rrr":
		if len(b) > 0:
			t = b.copy()
			b = [t[-1]].append([t[i-1] for i in range(1, len(t))])

	print("a > ", a, "\nb >", b)

print("Output > ", a, "Res > ", res)
if a == res:
	print("Good")
else:
	print("Bad")