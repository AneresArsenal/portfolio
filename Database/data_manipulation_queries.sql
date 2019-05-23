-- SELECT all club IDs and names and their respective income and expenditures for all years
SELECT cashflow.id, club.name AS club_name, year, amount
FROM club
INNER JOIN cashflow ON club.id = cashflow.club_id
ORDER BY cashflow.year, cashflow.amount DESC;

-- SELECT income and expenditures of a specific club for all years
SELECT cashflow.id, club.name AS club_name, year, amount
FROM club
INNER JOIN cashflow ON club.id = cashflow.club_id
WHERE club.id = :club_id_input
ORDER BY cashflow.year, cashflow.amount DESC;

-- SELECT all players and their current information
SELECT player.id, player.first_name, player.last_name, player.fee, player.market_value, country.name AS country_name, club.name AS club_name
FROM player 
INNER JOIN country ON player.country_id = country.id
INNER JOIN club ON player.club_id = club.id;

-- SELECT a specific player's current information
SELECT player.id, player.first_name, player.last_name, player.fee, player.market_value, country.name AS country_name, club.name AS club_name
FROM player 
INNER JOIN country ON player.country_id = country.id
INNER JOIN club ON player.club_id = club.id
WHERE player.name LIKE :player_name_input% LIMIT 1;

-- SELECT all leagues that a club has been part of
SELECT league.name, club_league.year FROM club
INNER JOIN club_league ON club.id = club_league.club_id 
INNER JOIN league ON league.id = club_league.league_id
WHERE club.name LIKE :club_name_input% LIMIT 1;

-- INSERT a new player
INSERT INTO player (club_id, first_name, last_name, country_id, fee, market_value)
VALUES (:club_id_input, :first_name_input, :last_name_input, :country_id_input, :fee_input, :market_value_input);

-- INSERT a new club
INSERT INTO club (`name`) 
VALUES (:name_input);

-- INSERT a new country
INSERT INTO country (`name`)
VALUES (:country_name_input);

-- INSERT a new league
INSERT INTO league (`name`)
VALUES (:league_name_input, :country_id_input);

-- INSERT a new cashflow record
INSERT INTO cashflow (club_id, year, amount) 
VALUES (:club_id_input, :year_input, :amount_input);

-- INSERT association a club with a league (M-to-M relationship addition)
INSERT INTO club_league (league_id, club_id, year) 
VALUES (:league_id_input, :club_id_input, :year_input);

-- UPDATE a player's information
UPDATE player SET first_name = :first_name_input, last_name = :last_name_input, country_id = :country_id_input, fee = :fee_input, market_value = :market_value_input 
WHERE player.name LIKE :player_name_input% LIMIT 1;

-- DELETE a player
DELETE FROM player 
WHERE player.name LIKE :player_name_input% LIMIT 1;

-- UPDATE a club's information
-- UPDATE club SET `name` = :name_input 
-- WHERE club.name LIKE :club_name_input% LIMIT 1;

-- UPDATE club relationship with a league (M-to-M relationship addition)
--UPDATE club_league  
--SET club_league.league_id = :league_id_input, club_league.year = :year_input
--WHERE club_league.club_id = :club_id_input ;

-- DELETE association of a club from a league (M-to-M relationship deletion)
DELETE FROM club_league WHERE club_league.league_id = :club_league_league_id_input AND club_league.club_id = :club_league_club_id_input;

