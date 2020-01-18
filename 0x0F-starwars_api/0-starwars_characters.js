#!/usr/bin/node

if (process.argv.length !== 3) {
  console.log('Usage: ./0-starwars_characters.js <film number>');
} else {
  const request = require('request');
  let chURL = 'https://swapi.co/api/people/';
  while (chURL !== null) {
    request(chURL, function (error, response, body) {
      if (error) {
        console.error(error);
        return;
      }
      const json = JSON.parse(body);
      const characters = json.results;
      chURL = json.next;
      characters.forEach(function (character) {
        const films = character.films;
        films.forEach(function (film) {
          if (film.includes(process.argv[2])) {
            console.log(character.name);
          }
        });
      });
    });
  }
}
