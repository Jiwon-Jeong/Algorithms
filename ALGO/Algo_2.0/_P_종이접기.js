function solution(n) {
  var answer = [0];
  let a = [0, 1];
  for (let j = 2; j <= n; j++) {
    let temp = answer.slice();
    answer.push(0);
    for (let j = temp.length - 1; j >= 0; j--) {
      if (temp[j] === 0) answer.push(1);
      else answer.push(0);
    }
  }
  return answer;
}
