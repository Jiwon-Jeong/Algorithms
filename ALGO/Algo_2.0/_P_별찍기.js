process.stdin.setEncoding("utf8");
process.stdin.on("data", (data) => {
  const n = data.split(" ");
  const a = Number(n[0]),
    b = Number(n[1]);
  let t = "";
  for (let i = 0; i < b; i++) {
    t = "";
    for (let j = 0; j < a; j++) {
      t += "*";
    }
    console.log(t);
  }
});
