function solution(w, h) {
  let answer = 1;
  for (let i = 1; i <= Math.min(w, h); i++) {
    if (w % i == 0 && h % i == 0) answer = i;
  }
  return w * h - (w + h - answer);
}
