function solution(nums) {
  function check(v) {
    for (let a = 2; a <= Math.sqrt(v); a++) {
      if (v % a == 0) return false;
    }
    return true;
  }

  let answer = 0;
  let len = nums.length;
  for (let i = 0; i < len; i++) {
    for (let j = i + 1; j < len; j++) {
      for (let k = j + 1; k < len; k++) {
        if (check(nums[i] + nums[j] + nums[k])) {
          answer++;
          console.log(i, j, k);
        }
      }
    }
  }
  return answer;
}
