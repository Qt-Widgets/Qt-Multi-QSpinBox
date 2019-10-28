QtMultiSpinBox
=================

The spin box (like QSpinBox) with user fields:

![Screenshot](https://github.com/Qt-Widgets/QtMultiSpinBox/blob/master/1.PNG)

Usage
=====
- Clone the repository :

        git clone https://vaysseb@bitbucket.org/vaysseb/qtmultispinbox.git lib/qtmultispinbox
    
- Add this line to the .pro file: 

        include($$PWD/lib/qtmultispinbox/qtmultispinbox.pri)

Sources
=====

The repository contains the source, with a test window.

It doesn't required any external components, just Qt framework (obviously).

Enjoy ! :-)


Example
=======
    #include <QApplication>
    #include <QVBoxLayout>

    #include <QtMultiSpinBox>
    #include <QtMultiSpinBoxElements>
    
    int main(int argc, char *argv[])
    {
        QApplication a(argc, argv);
    
        QWidget root;
        QtMultiSpinBox* spin = new QtMultiSpinBox(&root);
        spin->setPrefix("X=");
        spin->appendSpinElement(new QtIntMultiSpinBoxElement /* the x */, QLatin1String(" Y="));
        spin->appendSpinElement(new QtIntMultiSpinBoxElement /* the y */, QLatin1String(" Z="));
        spin->appendSpinElement(new QtIntMultiSpinBoxElement /* the z */);
    
        root.setLayout(new QVBoxLayout);
        root.layout()->addWidget(spin);
        root.show();
    
        return a.exec();
    }


Screenshots
=====

Example window:

![Example window](![Screenshot](https://github.com/Qt-Widgets/QtMultiSpinBox/blob/master/2.PNG))
