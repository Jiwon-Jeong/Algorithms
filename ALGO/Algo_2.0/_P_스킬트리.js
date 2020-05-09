function solution(skill, skill_trees) {
  let answer = 0;
  let s = skill.split("");
  let arr = [];

  for (let i = 0; i < skill_trees.length; i++) {
    arr = skill_trees[i]
      .split("")
      .filter((v) => s.includes(v))
      .join("");
    if (arr === skill.substring(0, arr.length)) answer++;
  }
  return answer;
}
