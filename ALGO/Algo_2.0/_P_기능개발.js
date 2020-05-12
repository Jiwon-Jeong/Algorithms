function solution(progresses, speeds) {
  let answer = [];
  let fin = progresses.map((v, i) => {
    v = 100 - v;
    if (v % speeds[i] !== 0) return parseInt(v / speeds[i] + 1);
    return parseInt(v / speeds[i]);
  });
  let cnt = 1;
  let max = fin[0];
  for (let i = 1; i < fin.length; i++) {
    if (fin[i] > max) {
      answer.push(cnt);
      max = fin[i];
      cnt = 1;
    } else {
      cnt++;
    }
    if (i === fin.length - 1) {
      answer.push(cnt);
    }
  }
  return answer;
}
