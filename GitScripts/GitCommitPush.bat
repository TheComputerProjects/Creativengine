@echo off

git add *
set /p commitTitle="Enter Commit Title: "
git commit -m "%commitTitle%"
git push
pause
