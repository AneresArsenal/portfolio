

-- get all club IDs and names
SELECT club.id, club.name
FROM club

-- get all club IDs and names and their respective income and expenditures for all years
SELECT *
FROM club
INNER JOIN cashflow ON club.id =cashflow.club_id
ORDER BY cashflow.year, cashflow.amount DESC

-- get all players and their current information
SELECT *
FROM player 
INNER JOIN country ON player.country_id = country.id
INNER JOIN country ON player.club_id = club.id

-- add a new player
INSERT INTO player (club_id, first_name, last_name, country_id, fee, market_value)
VALUES (:club_id_input, :first_name_input, :last_name_input, :country_id_input, :fee_input, :market_value_input)

-- add a new club
INSERT INTO club (`name`) 
VALUES (:name_input)

-- add a new cashflow record
INSERT INTO cashflow (club_id, year, amount) 
VALUES (:club_id_input, :year_input, :amount_input) 

-- associate a club with a league (M-to-M relationship addition)
INSERT INTO club_league (league_id, club_id, year) VALUES (:league_id_input, :club_id_input, :year_input) 

-- update a player's information
UPDATE player SET first_name = :first_name_input, last_name = :last_name_input, country = :country_id_input, fee = :fee_input, market_value = :market_value_input WHERE id = :player_id_input

-- delete a player
DELETE FROM player WHERE id = :player_id_input

-- update a club's information
UPDATE club SET `name` = :name_input, country = :country_id_input WHERE id = :club_id_input

-- delete a club
DELETE FROM club WHERE id = :club_id_input

-- dis-associate a certificate from a person (M-to-M relationship deletion)
DELETE FROM club_league WHERE league_id = :league_id_input AND club_id = :club_id_input AND year = :year_input
