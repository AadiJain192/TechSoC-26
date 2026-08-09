# TechSoC 2026

![Level](https://img.shields.io/badge/Level-Beginner_to_Advanced-2ea44f?style=flat-square)
![Language](https://img.shields.io/badge/Language-Any-0d6efd?style=flat-square)
![Format](https://img.shields.io/badge/Format-Self--Paced-9c27b0?style=flat-square)
![Elimination](https://img.shields.io/badge/Elimination-None-ff6f00?style=flat-square)

*A beginner-friendly coding challenge run for students of  IIT Indore.*

---

## So what is this, exactly?

TechSoC is how a lot of us at IIT Indore actually learned to code — not through a lecture, but by getting handed a problem that was just slightly out of reach and figuring it out. This year's version keeps that spirit: a handful of problem statements, released roughly every **10–12 days**, each one starting easy and getting harder as you go.

There's no cutoff round. Nobody gets eliminated for submitting a rough solution. The only way to not move forward is to not submit anything at all.

If you've never written a line of code, you can still do this. If you've been competitive programming for two years, there's enough in the later levels to keep you interested too.

## What to expect

Each problem statement has three levels baked in — so within one PS alone you're going from "get this working" to "now make it good." Early finishers also get bonus levels if they want to keep going instead of waiting around for the next release.

## Getting set up

If you haven't used Git or GitHub before, don't stress — there's a walkthrough in [RESOURCES.md](RESOURCES.md).

#### Step 1: Fork it

1. Create a GitHub account if you don't already have one
2. Click **Fork** at the top-right of this repository
3. Pick your account as the destination and let it finish

#### Step 2: Clone it

```bash
# Clone your forked repository
git clone https://github.com/<your-username>/TechSoC-26.git

# Move into the project folder
cd TechSoC-26

# Add the original repo as upstream so you can pull new problem statements
git remote add upstream https://github.com/godofwar1007/TechSoC-26.git

# Double check your remotes
git remote -v
```

If none of that made sense yet, that's fine — same walkthrough covers this in [RESOURCES.md](RESOURCES.md).

#### Directory structure

Once problem statements start dropping, your fork should look like this:

```
TechSoC-26/
├── README.md                          # Main challenge info
├── RESOURCES.md                       # Learning resources
├── Problem_Statement_1/
│   ├── README.md                      # Problem description
│   ├── your_solution.py/.cpp/...      # your solution, any language
│   ├── test_cases/                    # test files, if you made any
│   └── documentation.md               # your approach, briefly
```

#### Keeping your fork updated

```bash
# Pull in new problem statements from the original repo
git fetch upstream
git checkout main
git merge upstream/main
git push origin main
```

#### Submitting your work

```bash
git add .
git commit -m "Added solution for PS 1"
git push origin main
```

We'll send out a short Google Form asking for your repo link once a problem statement closes — that's how we know to go check out your work. Make sure everything's pushed before then.

## A note on working together

Talking through problems with other participants is completely fine — encouraged, even. Debug together, argue about approaches, share what confused you. But write your own code. This is one of the few times you'll get to solve something entirely on your own before you're thrown into club teams where you're relying on other people's code too. Use it.

## Need help?

Start with [RESOURCES.md](RESOURCES.md) — it's got video courses, docs, and interactive tutorials for both Python and C++, plus general Git/GitHub guides if that's what's tripping you up. Beyond that, search the specific concept you're stuck on, try breaking the problem into a smaller version first, and ask around in the community group. Getting stuck is normal — it's kind of the point.

---

## FAQs

**I've genuinely never coded before — can I still do this?**
Yes. Level 1 of each problem statement is built with complete beginners in mind. Start there, and use the resources guide alongside it — you're not expected to already know anything walking in.

**Does it matter which language I use?**
Not really. Python or C++ are what we'd recommend since most of the resources point that way, but if you're more comfortable in Java, JS, or something else, go for it. We're evaluating your problem-solving, not your syntax choice.

**How much time should I be putting into this per day?**
There's no fixed requirement, but as a rough guide: 2–3 hours a day if you're newer to this (including time spent learning), 1–2 hours if you've got some experience. Going slower and actually understanding it beats rushing through.

**What if I fall behind or start late?**
Every problem statement stays open the whole time, so there's no penalty for catching up later. Go at whatever pace makes sense for you.

**Can I work with a partner or submit as a team?**
No — solo submissions only. You'll be on teams constantly once you're in a club, so this is deliberately your chance to build things end-to-end by yourself. You can still talk to other people about ideas and get unstuck together, just don't share code.

**What do I actually need to participate?**
A laptop, an editor (VS Code works fine), a compiler or interpreter for whatever language you're using, and Git. All free, all easy to set up.

**How do I know if my solution is actually correct?**
Each PS folder comes with example inputs/outputs and a description of expected behavior. Write a few of your own test cases too — it's good practice and it'll catch edge cases the examples don't cover. We'll also give feedback once evaluations are done.

**Are there prizes?**
Not in the traditional sense — the real outcome here is walking away with working code you built yourself, some confidence going into club selections, and a portfolio of stuff you can point to later.

**I finished early — now what?**
Try the bonus level for that PS, clean up or optimize what you already built, try solving it in a different language, or just help someone else who's stuck. Whatever keeps you engaged until the next release.

---

Built by students at IIT Indore who figured most of this out by getting stuck and asking around — hoping this makes that process a little less lonely for you.

**⭐ Star the repo if this was useful to you.**
