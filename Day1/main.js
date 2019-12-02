// Day 1 is JS
const data = require('./input.json');

var totalFuel = 0;
for (const d of data) {
    var fuel = Math.floor(d / 3.0) -2;
    totalFuel += fuel;
}

console.log(totalFuel);