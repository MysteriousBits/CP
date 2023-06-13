import sys

brute = [*open('brute.out')]
out = [*open('output.out')]

for i in range(len(brute)):
    brute[i] = brute[i].replace('\n', '').strip()
for i in range(len(out)):
    out[i] = out[i].replace('\n', '').strip()

if '' in brute: brute.remove('')
if '' in out: out.remove('')

if len(brute) != len(out):
    print("! WA")
    print("Output length not equal.")
    quit()

for i in range(len(out)):
    if brute[i] != out[i]:
        print("! WA")
        print("Output doesn't match at line", i + 1)
        print("Expected:", brute[i])
        print("Yours:", out[i])
        sys.exit(1)

print("OK")
print("Output matched.")