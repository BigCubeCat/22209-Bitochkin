#!/bin/bash

echo "building server..."
cd server
mvn clean package
cd ..


echo "building client..."
cd client
mvn clean package
cd ..