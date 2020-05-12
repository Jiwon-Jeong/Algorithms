function solution(a, b) {
  var answer = "";

  const days = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"];
  let d = 4;
  for (let i = 1; i <= a; i++) {
    if (i === a) {
      d += b;
      break;
    } else {
      if (
        i === 1 ||
        i === 3 ||
        i === 5 ||
        i === 7 ||
        i === 8 ||
        i === 10 ||
        i === 12
      )
        d += 31;
      else if (i === 4 || i === 6 || i === 9 || i === 11) d += 30;
      else if (i == 2) d += 29;
    }
  }
  d %= 7;
  answer = days[d];
  return answer;
}
