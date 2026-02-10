FROM tomcat:9-jdk17-temurin

RUN apt-get update && apt-get install -y curl

RUN rm -rf ${CATALINA_HOME}/webapps/*

HEALTHCHECK CMD curl http://localhost:8080/ || exit 1

