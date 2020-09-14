SELECT name FROM directors JOIN people ON directors.person_id = people.id JOIN ratings ON directors.movie_id = ratings.movie_id WHERE rating >= 9.0;

