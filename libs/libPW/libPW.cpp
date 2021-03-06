/**
*-------------------------------------------------
*  Copyright 2016 by Tidop Research Group <daguilera@usal.se>
*
* This file is part of GRAPHOS - inteGRAted PHOtogrammetric Suite.
*
* GRAPHOS - inteGRAted PHOtogrammetric Suite is free software: you can redistribute
* it and/or modify it under the terms of the GNU General Public
* License as published by the Free Software Foundation, either
* version 3 of the License, or (at your option) any later version.
*
* GRAPHOS - inteGRAted PHOtogrammetric Suite is distributed in the hope that it will
* be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
* of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*
* @license GPL-3.0+ <http://spdx.org/licenses/GPL-3.0+>
*-------------------------------------------------
*/
#include <QFile>
#include <QMessageBox>
#include <Eigen/Dense>

#include "libPW.h"
#include "FraserModel.h"

using namespace PW;

QString                 LibPW::mMicMacBinPath = DEFAULT_MICMAC_BIN_PATH;
QString                 LibPW::mAsiftBinPath = DEFAULT_MICMAC_BIN_PATH;
QString                 LibPW::mOpenCVBinPath = DEFAULT_OPENCV_BIN_PATH;
QString                 LibPW::mOpenMVGBinPath = DEFAULT_OPENMVG_BIN_PATH;
QString                 LibPW::mMicMacWorkigPath = DEFAULT_MICMAC_WORKING_PATH;
QString                 LibPW::mPMVSPath = DEFAULT_PMVS_WORKING_PATH;
QString                 LibPW::mToolsPath = DEFAULT_TOOLS_BIN_PATH;
QString                 LibPW::mSUREBinPath = DEFAULT_SURE_BIN_PATH;

bool                    LibPW::mKeepMatchesInMemory = DEFAULT_KEEP_MATCHES_IN_MEMORY;
bool                    LibPW::mCleanProjectAtClossingEvent = DEFAULT_CLEAR_PROJECT_AT_CLOSSING;
float                   LibPW::mDefaultAccuracyToleranceForMatches = DEFAULT_DEFAULT_ACCURACY_TOLERANCE_FOR_MATCHES;

PersistenceManager *    LibPW::mPersistenceManager = NULL;
QString                 LibPW::mErrorPath = "";

LibPW::LibPW()
{
}

QString PW::LibPW::getMicMacBinPath()
{
    return mMicMacBinPath;
}

QString PW::LibPW::getMicMacWorkigPath()
{
    return mMicMacWorkigPath;
}

QString LibPW::getAsiftBinPath()
{
    return mAsiftBinPath;
}

QString PW::LibPW::getPMVSBinPath()
{
    return mPMVSPath;
}

void PW::LibPW::setMicMacBinPath(QString path)
{
    mMicMacBinPath = path;
}

QString PW::LibPW::getOpenCVBinPath()
{
    return mOpenCVBinPath;
}

QString PW::LibPW::getOpenMVGBinPath()
{
    return mOpenMVGBinPath;
}

QString PW::LibPW::getToolsPath()
{
    return mToolsPath;
}

bool PW::LibPW::getKeepMatchesInMemory()
{
    return mKeepMatchesInMemory;
}
bool PW::LibPW::getCleanProjectAtClossingEvent()
{
    return mCleanProjectAtClossingEvent;
}

float PW::LibPW::getDefaultAccuracyToleranceForMatches()
{
    return mDefaultAccuracyToleranceForMatches;
}

void PW::LibPW::setMicMacWorkigPath(QString path)
{
    mMicMacWorkigPath = path;
}

void LibPW::setAsiftBinPath(QString path)
{
    mAsiftBinPath = path;
}

void PW::LibPW::setPMVSBinPath(QString path)
{
    mPMVSPath = path;
}

void PW::LibPW::setOpenCVBinPath(QString path)
{
    mOpenCVBinPath = path;
}

void PW::LibPW::setOpenMVGBinPath(QString path)
{
    mOpenMVGBinPath = path;
}

void PW::LibPW::setToolsPath(QString path)
{
    mToolsPath = path;
}

void LibPW::setKeepMatchesInMemory(bool value)
{
    mKeepMatchesInMemory=value;
}

void LibPW::setCleanProjectAtClossingEvent(bool value)
{
    mCleanProjectAtClossingEvent=value;
}


void LibPW::setDefaultAccuracyToleranceForMatches(float value)
{
    mDefaultAccuracyToleranceForMatches=value;
}

void PW::LibPW::setPersistencePath(QString dbPath)
{
    if(mPersistenceManager != NULL)
        delete mPersistenceManager;
    mPersistenceManager = new PersistenceManager(dbPath);
    mPersistenceManager->openDatasource();
}

void PW::LibPW::setStdErrorPath(QString errorPath)
{
    mErrorPath = errorPath;
}

PW::PersistenceManager * PW::LibPW::getPersistenceManager()
{
    return mPersistenceManager;
}

QString PW::LibPW::getStdErrorPath()
{
    return mErrorPath;
}

bool PW::LibPW::validateAperoPath(QString path){
    if(!QFile(path + "/" + TAPIOCA_COMMAND).exists() && !QFile(path + "/" + TAPIOCA_COMMAND + ".exe").exists())
        return false;
    if(!QFile(path + "/" + APERICLOUD_COMMAND).exists() && !QFile(path + "/" + APERICLOUD_COMMAND + ".exe").exists())
        return false;
    if(!QFile(path + "/" + APERO_COMMAND).exists() && !QFile(path + "/" + APERO_COMMAND + ".exe").exists())
        return false;
    if(!QFile(path + "/" + MICMAC_COMMAND).exists() && !QFile(path + "/" + MICMAC_COMMAND + ".exe").exists())
        return false;
    if(!QFile(path + "/" + TAPAS_COMMAND).exists() && !QFile(path + "/" + TAPAS_COMMAND + ".exe").exists())
        return false;
    if(!QFile(path + "/" + BASCULE_COMMAND).exists() && !QFile(path + "/" + BASCULE_COMMAND + ".exe").exists())
        return false;
    if(!QFile(path + "/" + PORTO_COMMAND).exists() && !QFile(path + "/" + PORTO_COMMAND + ".exe").exists())
        return false;
    if(!QFile(path + "/" + NUAGE2PLY_COMMAND).exists() && !QFile(path + "/" + NUAGE2PLY_COMMAND + ".exe").exists())
        return false;
    return true;
}

bool PW::LibPW::validateAsiftPath(QString path){
    if(!QFile(path + "/" + ASIFT_KPD_COMMAND).exists() && !QFile(path + "/" + ASIFT_KPD_COMMAND + ".exe").exists())
        return false;
    if(!QFile(path + "/" + ASIFT_MATCHING_COMMAND).exists() && !QFile(path + "/" + ASIFT_MATCHING_COMMAND + ".exe").exists())
        return false;
    return true;
}

bool PW::LibPW::validatePMVSPath(QString path){
    if(!QFile(path + "/" + PMVS_PMVS_COMMAND).exists() && !QFile(path + "/" + PMVS_PMVS_COMMAND + ".exe").exists())
        return false;
    return true;
}

bool PW::LibPW::validateOpenCVPath(QString path){
    if(!QFile(path + "/" + OPENCV_KPM_COMMAND + ".exe" ).exists())
        return false;
    return true;
}

bool PW::LibPW::validateOpenMVGPath(QString path){
    if(!QFile(path + "/" + OPENMVG_KPM_COMMAND + ".exe" ).exists())
        return false;
    if(!QFile(path + "/" + OPENMVG_KPM_PROGRAM_KPDETECTCION + ".exe" ).exists())
        return false;
    if(!QFile(path + "/" + OPENMVG_KPM_PROGRAM_MATCHING + ".exe" ).exists())
        return false;
    return true;
}

bool LibPW::validateToolsPath(QString path)
{
    return true;
}

bool LibPW::validateSUREPath(QString path)
{
    return true;
}

bool LibPW::updateGCPPointsAccuracy(QMap<QString, PWImage *> imagesById,
                                    QMap<QString, QVector<double> > &geometryGCPs,
                                    QMap<QString, QMap<QString, QVector<double> > > &imageCoordinatesGCPs,
                                    QString &strError)
{
    // actualiza mGeometryGCPs pasando de (x,y,z,sx,sy,sz) a (x,y,z,sx,sy,sz,ex,ey,ez,e2d)
    // actualiza mImageCoordinatesGCPs de (x,y,std) a (x,y,std,ex,ey,e2d)
    QMap<QString, QVector<double> >::iterator iter=geometryGCPs.begin();
    while(iter!=geometryGCPs.end())
    {
        QString gcpName=iter.key();
        if(!imageCoordinatesGCPs.contains(gcpName))
        {
            //strError=QObject::tr("LibPW::updateGCPPointsAccuracy:: not measurement for GCP:%1").arg(gcpName);
            iter++;
            continue;
        }
        float x=iter.value()[0];
        float y=iter.value()[1];
        float z=iter.value()[2];
        QMap<QString, QVector<double> > imageCoordinatesGCP=imageCoordinatesGCPs[gcpName];
        QMap<QString, QVector<double> >::iterator iterIc=imageCoordinatesGCP.begin();
        // Primero cuento las imágenes para dimensionar la matriz
        int numberOfMeasuredImages=0;
        while(iterIc!=imageCoordinatesGCP.end())
        {
            QString imageId=iterIc.key();
            if(!imagesById.contains(imageId))
            {
                strError=QObject::tr("LibPW::updateGCPPointsAccuracy:: In GCP:%1 not found measured image %2")
                        .arg(gcpName)
                        .arg(imageId);
                return(false);
            }
            numberOfMeasuredImages++;
            iterIc++;
        }
        Eigen::MatrixXd A(2*numberOfMeasuredImages,3);
        Eigen::VectorXd b(2*numberOfMeasuredImages);
        int numberOfLine=0;
        iterIc=imageCoordinatesGCP.begin();
        while(iterIc!=imageCoordinatesGCP.end())
        {
            QString imageId=iterIc.key();
            numberOfMeasuredImages++;
            double xi=iterIc.value()[0];
            double yi=iterIc.value()[1];
            PW::PWImage* image=imagesById[imageId];
            int imageWidth=image->getSize().width();
            int imageHeight=image->getSize().height();
            PhotogrammetricModel *pm=(PhotogrammetricModel *)image->getCamera()->getCameraModel();
            double focal=pm->getFocal();
            double xpp=pm->getXp();
            double ypp=pm->getYp();
            QVector< QVector<double> > * r = image->getExteriorOrientation()->getR();
            QVector<double> * cp = image->getExteriorOrientation()->getCP();
            pm->undistort(xi,yi);
            double a=r->at(0).at(0)*xi+r->at(0).at(1)*yi+r->at(0).at(2)*focal;
            double d=r->at(1).at(0)*xi+r->at(1).at(1)*yi+r->at(1).at(2)*focal;
            double c=r->at(2).at(0)*xi+r->at(2).at(1)*yi+r->at(2).at(2)*focal;
            A(numberOfLine,0) = c;
            A(numberOfLine,1) = 0.0;
            A(numberOfLine,2) = -1.0*a;
            A(numberOfLine+1,0) = 0.0;
            A(numberOfLine+1,1) = c;
            A(numberOfLine+1,2) = -1.0*d;
            b(numberOfLine)=c*cp->at(0)-a*cp->at(2);
            b(numberOfLine+1)=c*cp->at(1)-d*cp->at(2);
            numberOfLine=numberOfLine+2;
            double xi_backward=0.0;
            double yi_backward=0.0;
            if(calculateImagePoint(x,y,z,pm,cp,r,
                                   imageWidth,imageHeight,
                                   xi_backward,yi_backward)==1)
            {
                return(false);
            }
            double xi_error=iterIc.value()[0]-xi_backward;
            double yi_error=iterIc.value()[1]-yi_backward;
            double i_accuracy=sqrt(xi_error*xi_error+yi_error*yi_error);
            imageCoordinatesGCPs[gcpName][imageId].push_back(xi_error);
            imageCoordinatesGCPs[gcpName][imageId].push_back(yi_error);
            imageCoordinatesGCPs[gcpName][imageId].push_back(i_accuracy);
            iterIc++;
        }
        Eigen::VectorXd sol=(A.transpose() * A).ldlt().solve(A.transpose() * b);
        Eigen::VectorXd residuals=A*sol-b;
        double res2d=sqrt(residuals(0)*residuals(0)+residuals(1)*residuals(1)+residuals(2)*residuals(2)+residuals(3)*residuals(3));
        double xT=sol(0);
        double yT=sol(1);
        double zT=sol(2);
        double ex=x-xT;
        double ey=y-yT;
        double ez=z-zT;
        double e2d=sqrt(ex*ex+ey*ey);
        geometryGCPs[gcpName].push_back(ex);
        geometryGCPs[gcpName].push_back(ey);
        geometryGCPs[gcpName].push_back(ez);
        geometryGCPs[gcpName].push_back(e2d);
        iter++;
    }
    return(true);
}

bool LibPW::updateTiePointsAccuracy(QMap<QString, PWImage *> imagesById,
                                    QMap<QString, QMap<QString, QVector<double> > > &orientationImagesFirstColumnsTiePoints,
                                    QMap<QString, QMap<QString, QVector<double> > > &orientationImagesFirstRowsTiePoints,
                                    QMap<QString, QMap<QString, QVector<double> > > &orientationImagesSecondColumnsTiePoints,
                                    QMap<QString, QMap<QString, QVector<double> > > &orientationImagesSecondRowsTiePoints,
                                    QMap<QString, QMap<QString, QVector<int> > > &orientationMatchesIds,
                                    QMap<QString, QMap<QString, QVector<double> > > &orientationMatchesAccuracies,
                                    QMap<int, double> &accuraciesByMatchId,
                                    QString& strError)
{
    orientationMatchesAccuracies.clear();
    accuraciesByMatchId.clear();
    QMap<QString, QMap<QString, QVector<int> > >::const_iterator iter=orientationMatchesIds.begin();
    while(iter!=orientationMatchesIds.end())
    {
        QString firstImageId=iter.key();
        //PW::PWImage* firstImage=this->getImageByName(firstImageId);
        if(!imagesById.contains(firstImageId))
        {
            strError=QObject::tr("LibPW::updateTiePointsAccuracy:: image id: %1 not found").arg(firstImageId);
        }
        PW::PWImage* firstImage=imagesById[firstImageId];
        int firstImageWidth=firstImage->getSize().width();
        int firstImageHeight=firstImage->getSize().height();
        PhotogrammetricModel *pm1=(PhotogrammetricModel *)firstImage->getCamera()->getCameraModel();
        double focal1=pm1->getFocal();
        double xpp1=pm1->getXp();
        double ypp1=pm1->getYp();
        QVector< QVector<double> > * r1 = firstImage->getExteriorOrientation()->getR();
        QVector<double> * cp1 = firstImage->getExteriorOrientation()->getCP();
        QMap<QString, QVector<int> > matchesIdsByFirstImage=iter.value();
        QMap<QString, QVector<int> >::const_iterator iterBis=matchesIdsByFirstImage.begin();
        QMap<QString, QVector<double> > matchesAccuraciesByFirstImage;
        while(iterBis!=matchesIdsByFirstImage.end())
        {
            QString secondImageId=iterBis.key();
            if(!imagesById.contains(secondImageId))
            {
                strError=QObject::tr("LibPW::updateTiePointsAccuracy:: image id: %1 not found").arg(secondImageId);
            }
            PW::PWImage* secondImage=imagesById[secondImageId];
            int secondImageWidth=secondImage->getSize().width();
            int secondImageHeight=secondImage->getSize().height();
            QVector< QVector<double> > * r2 = secondImage->getExteriorOrientation()->getR();
            QVector<double> * cp2 = secondImage->getExteriorOrientation()->getCP();
            QVector<int> matchesIds=iterBis.value();
            PhotogrammetricModel *pm2=(PhotogrammetricModel *)secondImage->getCamera()->getCameraModel();
            double focal2=pm2->getFocal();
            double xpp2=pm2->getXp();
            double ypp2=pm2->getYp();
            QVector<double> firstImageColumns=orientationImagesFirstColumnsTiePoints[firstImageId][secondImageId];
            QVector<double> firstImageRows=orientationImagesFirstRowsTiePoints[firstImageId][secondImageId];
            QVector<double> secondImageColumns=orientationImagesSecondColumnsTiePoints[firstImageId][secondImageId];
            QVector<double> secondImageRows=orientationImagesSecondRowsTiePoints[firstImageId][secondImageId];
            QVector<double> accuracies;
            for(int nM=0;nM<matchesIds.size();nM++)
            {
                int matchId=matchesIds[nM];
                double x1=firstImageColumns[nM];
                double y1=firstImageRows[nM];
                double x2=secondImageColumns[nM];
                double y2=secondImageRows[nM];
                double accuracy=0.0;
                pm1->undistort(x1,y1);
                pm2->undistort(x2,y2);
                double a1=r1->at(0).at(0)*x1+r1->at(0).at(1)*y1+r1->at(0).at(2)*focal1;
                double d1=r1->at(1).at(0)*x1+r1->at(1).at(1)*y1+r1->at(1).at(2)*focal1;
                double c1=r1->at(2).at(0)*x1+r1->at(2).at(1)*y1+r1->at(2).at(2)*focal1;
                double a2=r2->at(0).at(0)*x2+r2->at(0).at(1)*y2+r2->at(0).at(2)*focal2;
                double d2=r2->at(1).at(0)*x2+r2->at(1).at(1)*y2+r2->at(1).at(2)*focal2;
                double c2=r2->at(2).at(0)*x2+r2->at(2).at(1)*y2+r2->at(2).at(2)*focal2;
                Eigen::MatrixXd A(4,3);
                A(0,0) = c1;
                A(0,1) = 0.0;
                A(0,2) = -1.0*a1;
                A(1,0) = 0.0;
                A(1,1) = c1;
                A(1,2) = -1.0*d1;
                A(2,0) = c2;
                A(2,1) = 0.0;
                A(2,2) = -1.0*a2;
                A(3,0) = 0.0;
                A(3,1) = c2;
                A(3,2) = -1.0*d2;
                Eigen::VectorXd b(4);
                b(0)=c1*cp1->at(0)-a1*cp1->at(2);
                b(1)=c1*cp1->at(1)-d1*cp1->at(2);
                b(2)=c2*cp2->at(0)-a2*cp2->at(2);
                b(3)=c2*cp2->at(1)-d2*cp2->at(2);
                Eigen::VectorXd sol=(A.transpose() * A).ldlt().solve(A.transpose() * b);
                Eigen::VectorXd residuals=A*sol-b;
                double res2d=sqrt(residuals(0)*residuals(0)+residuals(1)*residuals(1)+residuals(2)*residuals(2)+residuals(3)*residuals(3));

                double xT=sol(0);
                double yT=sol(1);
                double zT=sol(2);
                double x1_backward=0.0;
                double y1_backward=0.0;
                double x2_backward=0.0;
                double y2_backward=0.0;
                if(calculateImagePoint(xT,yT,zT,pm1,cp1,r1,
                                       firstImageWidth,firstImageHeight,
                                       x1_backward,y1_backward)==1)
                {
                    return(false);
                }
                if(calculateImagePoint(xT,yT,zT,pm2,cp2,r2,
                                       secondImageWidth,secondImageHeight,
                                       x2_backward,y2_backward)==1)
                {
                    return(false);
                }
                double x1_error=firstImageColumns[nM]-x1_backward;
                double y1_error=firstImageRows[nM]-y1_backward;
                double x2_error=secondImageColumns[nM]-x2_backward;
                double y2_error=secondImageRows[nM]-y2_backward;
                accuracy=sqrt(x1_error*x1_error+y1_error*y1_error+x2_error*x2_error+y2_error*y2_error);
//                A=[c1   0  -a1
//                    0  c1  -d1
//                   c2   0  -a2
//                    0  c2  -d2];
//                b=[c1*XC1(1)-a1*XC1(3)
//                   c1*XC1(2)-d1*XC1(3)
//                   c2*XC2(1)-a2*XC2(3)
//                   c2*XC2(2)-d2*XC2(3)];
//                X=inv(A'*A)*(A'*b);
//                R=A*X-b;
//                xT=X(1);
//                yT=X(2);
//                zT=X(3);
                accuracies.push_back(accuracy);
                accuraciesByMatchId[matchId]=accuracy;
            }
            matchesAccuraciesByFirstImage[secondImageId]=accuracies;
            iterBis++;
        }
        orientationMatchesAccuracies[firstImageId]=matchesAccuraciesByFirstImage;
        iter++;
    }
    return(true);
}

int LibPW::calculateImagePoint(double xT,
                               double yT,
                               double zT,
                               PhotogrammetricModel *pm,
                               QVector<double> *cp,
                               QVector<QVector<double> > *r,
                               int imgWidth,
                               int imgHeight,
                               double &column,
                               double &row)
{
    double xImg = pm->getFocal()*(r->at(0).at(0) * (xT - cp->at(0)) +
                               r->at(1).at(0) * (yT - cp->at(1)) +
                               r->at(2).at(0) * (zT - cp->at(2))) /
                              (r->at(0).at(2) * (xT - cp->at(0)) +
                               r->at(1).at(2) * (yT - cp->at(1)) +
                               r->at(2).at(2) * (zT - cp->at(2)));

    double yImg = pm->getFocal()*(r->at(0).at(1) * (xT - cp->at(0)) +
                               r->at(1).at(1) * (yT - cp->at(1)) +
                               r->at(2).at(1) * (zT - cp->at(2))) /
                              (r->at(0).at(2) * (xT - cp->at(0)) +
                               r->at(1).at(2) * (yT - cp->at(1)) +
                               r->at(2).at(2) * (zT - cp->at(2)));
    xImg+=pm->getXp();
    yImg+=pm->getYp();
    pm->distort(xImg,yImg);
    column = pm->getXp() + xImg;
    row = pm->getYp() + yImg;
    return(0);
}
QString LibPW::getSUREBinPath()
{
    return mSUREBinPath;
}

void LibPW::setSUREBinPath(QString value)
{
    mSUREBinPath = value;
}

bool LibPW::removeDir(QString dirName)
{
    bool result = true;
    QDir dir(dirName);
    if (dir.exists(dirName)) {
        Q_FOREACH(QFileInfo info, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::System | QDir::Hidden  | QDir::AllDirs | QDir::Files, QDir::DirsFirst)) {
            if (info.isDir()) {
                result = removeDir(info.absoluteFilePath());
            }
            else {
                result = QFile::remove(info.absoluteFilePath());
            }
            if (!result) {
                return result;
            }
        }
        result = dir.rmdir(dirName);
    }
    return result;
}

bool LibPW::copyDir(QString sourceFolder, QString destFolder, bool move)
{
//    QDir auxDir=QDir::currentPath();
//    if(!auxDir.exists(sourceFolder))
//        return(false);
    QDir sourceDir(sourceFolder);
    if(!sourceDir.exists())
        return(false);
    QDir destDir(destFolder);
    if(!destDir.exists())
    {
        QDir().mkdir(destFolder);
    }
    QStringList files = sourceDir.entryList(QDir::Files);
    for(int i = 0; i< files.count(); i++)
    {
        QString srcName = sourceFolder + "/" + files[i];
        QString destName = destFolder + "/" + files[i];
        QFile::copy(srcName, destName);
        if (move)
            QFile::remove(srcName);
    }
    files.clear();
    files = sourceDir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);
    for(int i = 0; i< files.count(); i++)
    {
        QString srcName = sourceFolder + "/" + files[i];
        QString destName = destFolder + "/" + files[i];
        copyDir(srcName, destName, move);
    }
    if(move){
        if (sourceDir.exists()) {
            removeDir(sourceDir.absolutePath());
            }
    }
    return true;
}
