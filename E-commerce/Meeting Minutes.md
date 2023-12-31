﻿Meeting Minutes - Database Management and Web Visualization

Date: June

Location: Beijing University of Posts and Telecommunications

Attendees:

\- Zuo Jinhao

\- Jia Fanbo

\- Shan Yunlai

Agenda:

1\. Database Design

2\. Web Application Functions

3\. Advanced Functions

4\. Next Steps

Meeting Highlights:

1\. Database Design:

During the meeting, we delved further into the details of the database design for the web application. We discussed the specific fields for each table and their data types. Here are the details:

\- User Accounts Table:

- Fields:

- user\_id: unique identifier for each user (integer or UUID)

- username: the username chosen by the user (string)

- password: password for user authentication (hashed string)

- robot\_id: unique identifier for the user's associated robot (integer or UUID)



\- Robot Information Table:

- Fields:

- robot\_id: unique identifier for each robot (integer or UUID)

- name: name of the robot (string)

- picture: URL or file path pointing to the robot's picture (string)

- [Other relevant fields]: additional fields to store information about the robot, such as model, manufacturer, etc.

\- Exploration Records Table:

- Fields:

- record\_id: unique identifier for each exploration record (integer or UUID)

- robot\_id: identifier linking the exploration record to the corresponding robot (integer or UUID)

- maze\_exploration\_time: duration in seconds for the robot to complete the maze exploration (integer or float)

- treasure\_statistics: statistics regarding the treasures found during exploration (string or JSON)

- [Other relevant fields]: additional fields to capture any other relevant data about the exploration

Regarding the relationships between tables, the user\_id field in the User Accounts Table will serve as the primary key. The robot\_id field in the Robot Information Table will be a foreign key referencing the robot associated with each user. Similarly, the robot\_id field in the Exploration Records Table will be a foreign key linking exploration records to their corresponding robots.

2\. Web Application Functions:

We provided more details on the required functions for the web application. Here are the expanded descriptions:

\- User Login:

- Users will be able to enter their username and password to log in to the web application.

- The system will authenticate the user's credentials and grant access to their robot's account upon successful login.

\- Account Management:

- Users will have the ability to add, delete, and modify information related to their robot account.

- The add function will allow users to create a new robot account by providing the necessary details, such as name, picture, etc.

- The delete function will enable users to remove their robot account from the system.

- The modify function will allow users to update fields such as name, picture, and any other relevant information associated with their robot.

\- Exploration Record Visualization:

- We discussed various ways to visualize exploration records for users to gain insights.

- Possible visualization options include:

- Displaying average maze exploration time as a line chart or bar graph.

- Presenting statistics of treasures found using pie charts or tables.

- Providing a summary dashboard with key metrics and visual representations of exploration records.

3\. Advanced Functions:

We explored additional advanced functions that could enhance the web application's capabilities:

\- Real-Time Data Display:

- We discussed the possibility of integrating real-time data from the robot into the web application.

- This could involve displaying real-time maps generated by the robot, streaming pictures from its camera, or presenting other sensor readings.

- To achieve this, we will need to investigate the robot's API and determine the data format and integration possibilities.

4\. Next Steps:

To move forward with the development of the web application, we defined the following next steps:

\- Zuo Jinhao: Research different data visualization techniques and frameworks suitable for web application development, considering factors such as ease of use, compatibility, and scalability.

\- Jia Fanbo: Design the database schema, ensuring proper normalization and establishing the necessary relationships between tables. Create the required SQL scripts for table creation.

\- Shan Yunlai: Implement user login functionality, including secure password hashing and session management to ensure user authentication and authorization.

Meeting Adjourned.
