#include <iostream>
#include <libxml++/libxml++.h>
#include <QtCore/QtCore>

using namespace std;

bool checkXML(const QString &);

int main() {
    Q_INIT_RESOURCE(resources);
    qDebug() << checkXML(":/XmlParser.xml");
}

bool checkXML(const QString &fileName) {
    try {
        QFile schemaFile(":/parser.xsd");
        schemaFile.open(QFile::ReadOnly);
        xmlpp::XsdSchema schema;
        schema.parse_memory(schemaFile.readAll().toStdString());
        xmlpp::XsdValidator validator(&schema, false);
        try {
            QFile xmlFile(fileName);
            xmlFile.open(QFile::ReadOnly);
            xmlpp::DomParser parser;
            parser.parse_memory(xmlFile.readAll().toStdString());
            parser.set_throw_messages();
            validator.validate(parser.get_document());
        } catch (const std::exception &e) {
            std::cout << "Exception: " << e.what();
            return false;
        }
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what();
        return false;
    }
    return true;
}
