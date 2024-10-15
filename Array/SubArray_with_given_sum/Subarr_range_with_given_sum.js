const arr = [10, 2, -2, -20, 10];

const tar = -10;

let sum = 0;
let count = 0;

for (let i = 0; i < arr.length; i++) {
     sum = 0;
     for (let j = i; j < arr.length; j++) {
          sum+=arr[j];
          if (sum == tar) {
               count+=1;
               console.log(i, j);
          }
     }
}

console.log(`The Total subarray present is ${count}`);


