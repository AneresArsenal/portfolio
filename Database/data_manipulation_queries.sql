

-- get all club IDs and names
SELECT club.id, club.name
FROM club;

-- get all club IDs and names and their respective income and expenditures for all years
SELECT *
FROM club
INNER JOIN cashflow ON club.id = cashflow.club_id
ORDER BY cashflow.year, cashflow.amount DESC;

-- get income and expenditures of a specific club for all years
SELECT *
FROM club
INNER JOIN cashflow ON club.id =cashflow.club_id
WHERE club.id = :club_id_input
ORDER BY cashflow.year, cashflow.amount DESC;

-- get all players and their current information
SELECT player.first_name, player.last_name, player.fee, player.market_value, country.name, club.name
FROM player 
INNER JOIN country ON player.country_id = country.id
INNER JOIN club ON player.club_id = club.id;

-- get a specific player's current information
SELECT player.first_name, player.last_name, player.fee, player.market_value, country.name, club.name
FROM player 
INNER JOIN country ON player.country_id = country.id
INNER JOIN club ON player.club_id = club.id
WHERE player.id = :player_id_input

-- get all leagues that a club has been part of
SELECT league.name, club_league.year FROM club
INNER JOIN club_league ON club.id = club_league.club_id 
INNER JOIN league ON league.id = club_league.league_id
WHERE club.id = :club_id_input

-- add a new player
INSERT INTO player (club_id, first_name, last_name, country_id, fee, market_value)
VALUES (:club_id_input, :first_name_input, :last_name_input, :country_id_input, :fee_input, :market_value_input);

-- add a new club
INSERT INTO club (`name`) 
VALUES (:name_input);

-- add a new country
INSERT INTO country (`name`)
VALUES (:country_name_input);

-- add a new cashflow record
INSERT INTO cashflow (club_id, year, amount) 
VALUES (:club_id_input, :year_input, :amount_input);

-- associate a club with a league (M-to-M relationship addition)
INSERT INTO club_league (league_id, club_id, year) VALUES (:league_id_input, :club_id_input, :year_input);

-- update a player's information
UPDATE player SET first_name = :first_name_input, last_name = :last_name_input, country_id = :country_id_input, fee = :fee_input, market_value = :market_value_input WHERE id = :player_id_input;

-- delete a player
DELETE FROM player WHERE id = :player_id_input;

-- update a club's information
UPDATE club SET `name` = :name_input WHERE club.id = :club_id_input;

-- dis-associate a club from a league (M-to-M relationship deletion)
DELETE FROM club_league WHERE club_league.league_id = :club_league_league_id_input AND club_league.club_id = :club_league_club_id_input;
