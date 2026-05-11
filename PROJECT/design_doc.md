# Design Document Template — Project 4

**Name:** Justin Tran
**Track:** A
**Project Title:**  BAD APPLE 3D CONSOLE
**One-sentence pitch:** What does your program do, in plain language?
Plays Bad Apple in the console in ASCII, along with a 3d effect. 
---

## 1. The Problem

What does your program solve or provide? Who would use it? Write 2–3 sentences. No jargon.
We all know the standard Bad Apple implementations, but 3D Bad Apple is a lot more rare. So I just think its neat and interesting. 

> *Example: "A text-based inventory tracker for tabletop RPG players. The user adds, removes, and searches items by category. It saves the inventory to a file so it persists between sessions."*

---

## 2. State Inventory

List every piece of data your program tracks. For each, note its type and what changes it.

It tracks the current pixels on queue to be drawn next frame. 

> **Track C note:** Use plain-language types (number, text, list, true/false). The thinking matters more than the syntax.

---

## 3. Function / Component Map

Break your program into pieces. Each piece does one job.

drawFrame() - Draws entire frame from array. 
drawPixel(x, y) - Modify one element of array at specific x, y location. 

> Aim for at least 5 entries at B tier, 7+ at A tier. If a function does two unrelated things, split it.

---

## 4. User Flow

Describe what happens from the moment the user runs the program to when they quit. Use numbered steps or a simple flowchart. Focus on the *main path* first, then note branches.

**Main path:**

1. Run program file
2. Program plays with player input
3. Program ends and exits automatically

**Key branches:**

- If the user does X → ...
- If the file doesn't exist → ...
- If input is invalid → ...

---

## 5. What Could Go Wrong

List at least 3 things that could break or confuse the user. For each, state your plan.

1. 3D effects might not be clear in ASCII. Solution is to just remove it. 
2. Audio might not work in codespace. Solution is to not have audio. 
3. Window might be too small for the program. Solution is to shrink resolution. 

---

## 6. What I'll Ask AI to Help With

Be specific. "Help me code it" is not a plan. Good entries name the *task* and the *reason*.

1. Write parser of data.bin.
2. Make data.bin from an mp4 file. 
3. Write RLE-DELTA Compression Algorithm. 
4. Make Grid and Render Class.

---

## 7. What I'll Do Myself (No AI)

Name at least 2 parts you'll write or solve without AI assistance. These should be things where the struggle is the learning.

1. I will give it the specific algorithms to use. 
2. I will do the file splitting/chunking so its not one massive file. 

---

## 8. Scope Check

Answer honestly:

- Can I build the C-tier version in one focused work session? **yes / no / unsure**
Yes
- Does every feature in my plan connect to the core interaction? **yes / no**
Yes
- Have I cut anything that's "nice to have" but not essential? **yes / no**
No
> If you answered "no" or "unsure" to the first question, your scope is too large. Cut features until the answer is yes, then add B/A tier features as stretch goals.

---

## Instructor Approval

*To be filled out during Week 13 check-in:*

- [ ] Scope is appropriate
- [ ] State inventory is complete
- [ ] Function map shows clear decomposition
- [ ] Student knows what they'll ask AI for and what they'll do themselves

**Notes:**

