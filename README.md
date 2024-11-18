# School_Information_System
School Information Management System
This project involves implementing a simple university personnel management 
program. The program deals with two different kinds of personnel: students 
and faculty. For each person, the program stores relevant information such 
as university ID, name … etc. Different information is stored depending on 
the type of the person. For example, a student has a GPA, while a faculty
has a title (like professor) and department (like math).
# Student is characterized with:
- Full name : String
- ID: String
- Gpa: float
- Number of credit hours currently taken: int
# Faculty class has:
- Full name: String
- ID: String
- Department (math, cs or science are the only departments we are 
considering in this project)
- Rank (professor and adjunct are the only ranks we are considering in this 
project)
Students in this college pay $236.45 per one credit hour in addition to a 
$52 administrative fee. Note that students get a 25% off total payment if 
their gpa is greater or equal to 3.85.
Your code should be able to handle up to 100 students and up to 30 faculty 
members. You may use any data structure of your choosing to store the 
students/faculty information (arrays, linked lists…etc.)
Please note well that:
1) Your code should run exactly as shown on the sample run below (However, the TA will not deduct points because you skipped two lines instead of three or your tuition invoice has 56 hyphens instead of 63).
2) When asked to enter the faculty’s department, math, mAth, Math … and MATH are considered to be the same. However, if the user enters Mathematics or Math department, then that is an invalid entry. Consider these departments only: math, cs or science. As for the rank of a faculty, consider these ranks only: professor or adjunct.
3) All string entries (names of people, department , ranks…) are stored in capital. For example, if the user enters math, then your code converts it to MATH
4) The university ID must be of the same format as the UCF’s nid with no spaces in between(letterletterdigitdigitdigitdigitdigitdigit). But ab123456 is the same as aB123456, Ab123456 or AB123456
5) You may assume that the user enters one character when asked to enter a menu option.
6) The program terminates if the user fails to enter the correct information after trying three times.
   _For example:_
*Enter the faculty’s info:*
Name of the faculty: Edward Saeed
ID: gz789449
Rank: Instructor
Sorry entered rank (Instructor) is invalid. Try again.
Rank: Assistant Prof
_Sorry entered rank (Assistant Prof) is invalid. Try again._
Rank: Prof
_You have tried too many times…_
_Thank you for using SIMS. Goodbye_
