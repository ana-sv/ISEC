% DerivacaoNumerica Derivação Numérica
% Máquina para calcular soluções aproximadas de derivadas
% --- 12/01/2016  Arménio Correia   armenioc@isec.pt


function varargout = DerivacaoNumerica(varargin)
% DERIVACAONUMERICA M-file for DerivacaoNumerica.fig
%      DERIVACAONUMERICA, by itself, creates a new DERIVACAONUMERICA or raises the existing
%      singleton*.
%
%      H = DERIVACAONUMERICA returns the handle to a new DERIVACAONUMERICA or the handle to
%      the existing singleton*.
%
%      DERIVACAONUMERICA('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in DERIVACAONUMERICA.M with the given input arguments.
%
%      DERIVACAONUMERICA('Property','Value',...) creates a new DERIVACAONUMERICA or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before DerivacaoNumerica_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to DerivacaoNumerica_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help DerivacaoNumerica

% Last Modified by GUIDE v2.5 24-May-2017 23:16:30

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @DerivacaoNumerica_OpeningFcn, ...
                   'gui_OutputFcn',  @DerivacaoNumerica_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before DerivacaoNumerica is made visible.
function DerivacaoNumerica_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to DerivacaoNumerica (see VARARGIN)

% Choose default command line output for DerivacaoNumerica
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes DerivacaoNumerica wait for user response (see UIRESUME)
% uiwait(handles.figureDerivacaoNumerica);
MyAtualizar(handles);


% --- Outputs from this function are returned to the command line.
function varargout = DerivacaoNumerica_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in pbAtualiza.
function pbAtualiza_Callback(hObject, eventdata, handles)
% hObject    handle to pbAtualiza (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
MyAtualizar(handles);


function eA_Callback(hObject, eventdata, handles)
% hObject    handle to eA (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of eA as text
%        str2double(get(hObject,'String')) returns contents of eA as a double


% --- Executes during object creation, after setting all properties.
function eA_CreateFcn(hObject, eventdata, handles)
% hObject    handle to eA (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function eH_Callback(hObject, eventdata, handles)
% hObject    handle to eH (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of eH as text
%        str2double(get(hObject,'String')) returns contents of eH as a double


% --- Executes during object creation, after setting all properties.
function eH_CreateFcn(hObject, eventdata, handles)
% hObject    handle to eH (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function eB_Callback(hObject, eventdata, handles)
% hObject    handle to eB (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of eB as text
%        str2double(get(hObject,'String')) returns contents of eB as a double


% --- Executes during object creation, after setting all properties.
function eB_CreateFcn(hObject, eventdata, handles)
% hObject    handle to eB (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes when user attempts to close figureDerivacaoNumerica.
function figureDerivacaoNumerica_CloseRequestFcn(hObject, eventdata, handles)
% hObject    handle to figureDerivacaoNumerica (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: delete(hObject) closes the figure
%delete(hObject);
set(hObject,'Visible','Off');

% --- Função auxiliar associada ao botão Atualizar.
function MyAtualizar(handles)
% handles estrutura de dados com as handles para os objetos...
syms x;
strF=get(handles. tFuncao,'String');
f=@(x) eval(vectorize(char(strF)));
df=diff(f(x));
a=str2num(get(handles.eA,'String'));
h=str2num(get(handles.eH,'String'));
b=str2num(get(handles.eB,'String'));


escolhaBG=get(handles.bgFormulasDNumerica,'SelectedObject');
escolha=find([handles.rbDFP,...
              handles.rbDFR,...
              handles.rbDFC,...
              handles.rbDFP_tres,...
              handles.rbDFR_tres]==escolhaBG);
Progressivas=1;
Regressivas=2;
Centradas=3;
Progressivas3pontos=4;
Regressivas3pontos=5;
%Trapezios=6;
%Simpson=7;

%Excepções
%erroF=MException('MATLAB:MyActualizar:badFun','Introduza uma função em t e y');
%testNReal=MException('MATLAB:MyAtualiza:badF','Introduza um número real');
%...
       
try          

    [x,y,dydxDFP]=NDerivacaoDFP(f,a,b,h);
    [~,~,dydxDFR]=NDerivacaoDFR(f,a,b,h);
    [~,~,dydxDFC]=NDerivacaoDFC(f,a,b,h);
    [x,y,dydxDFP_tres]=NDerivacaoDFP3pontos(f,a,b,h,y);
    [x,y,dydxDFR_tres]=NDerivacaoDFR3pontos(f,a,b,h,y);
   % T=RTrapezios(f,a,b,n);
    %out_S=RSimpson(f,a,b,n);
    dydxExata=eval(df);

    

    
    switch escolha
        case Progressivas
            
erroDFP=abs(dydxExata-dydxDFP);
plot(x,y,'-bo');
hold on
plot(x,dydxDFP,'-r+');
plot(x,dydxExata,'-ks');
hold off;
legend('Função','DerivadaDFP','DExata');
set(handles.uitabela,'ColumnName',[{'x'},{'y'},{'DNumerica'},{'DExata'},{'Erro'}]);
set(handles.uitabela,'Data',num2cell([x.',y.',dydxDFP.',dydxExata.',erroDFP.']));
       
        
        case Regressivas
            
erroDFR=abs(dydxExata-dydxDFR);
plot(x,y,'-bo');
hold on
plot(x,dydxDFR,'-r+');
plot(x,dydxExata,'-ks');
hold off;
legend('Função','DerivadaDFR','DExata');
set(handles.uitabela,'ColumnName',[{'x'},{'y'},{'DNumerica'},{'DExata'},{'Erro'}]);
set(handles.uitabela,'Data',num2cell([x.',y.',dydxDFR.',dydxExata.',erroDFR.']));
            
        case Centradas
            
           erroDFC=abs(dydxExata-dydxDFC);
plot(x,y,'-bo');
hold on
plot(x,dydxDFC,'-r+');
plot(x,dydxExata,'-ks');
hold off;
legend('Função','DerivadaDFC','DExata');
set(handles.uitabela,'ColumnName',[{'x'},{'y'},{'DNumerica'},{'DExata'},{'Erro'}]);
set(handles.uitabela,'Data',num2cell([x.',y.',dydxDFC.',dydxExata.',erroDFC.']));

        case Progressivas3pontos
            
             erroDFP_tres=abs(dydxExata-dydxDFP_tres);
plot(x,y,'-bo');
hold on
plot(x,dydxDFP_tres,'-r+');
plot(x,dydxExata,'-ks');
hold off;
legend('Função','DerivadaDFP 3 pontos','DExata');
set(handles.uitabela,'ColumnName',[{'x'},{'y'},{'DNumerica'},{'DExata'},{'Erro'}]);
set(handles.uitabela,'Data',num2cell([x.',y.',dydxDFP_tres.',dydxExata.',erroDFP_tres.']));
            

        case Regressivas3pontos
            
           erroDFR_tres=abs(dydxExata-dydxDFR);
plot(x,y,'-bo');
hold on
plot(x,dydxDFR_tres,'-r+');
plot(x,dydxExata,'-ks');
hold off;
legend('Função','DerivadaDFR 3 pontos','DExata');
set(handles.uitabela,'ColumnName',[{'x'},{'y'},{'DNumerica'},{'DExata'},{'Erro'}]);
set(handles.uitabela,'Data',num2cell([x.',y.',dydxDFR_tres.',dydxExata.',erroDFR_tres.']));
            
%         case Trapezios
%             
%  erroT=abs(dydxExata-dydx);
% plot(x,y,'-bo');
% hold on
% plot(x,dydx,'-r+');
% plot(x,dydxExata,'-ks');
% hold off;
% legend('Função','DerivadaT','DExata');
% set(handles.uitabela,'ColumnName',[{'x'},{'y'},{'DNumerica'},{'DExata'},{'Erro'}]);
% set(handles.uitabela,'Data',num2cell([x.',y.',dydx.',dydxExata.',erroT.']));
% 
%         case Simpson
%             
%              erroS=abs(dydxExata-dydx);
% plot(x,y,'-bo');
% hold on
% plot(x,dydx,'-r+');
% plot(x,dydxExata,'-ks');
% hold off;
% legend('Função','DerivadaS','DExata');
% set(handles.uitabela,'ColumnName',[{'x'},{'y'},{'DNumerica'},{'DExata'},{'Erro'}]);
% set(handles.uitabela,'Data',num2cell([x.',y.',dydx.',dydxExata.',erroS.']));
% 
     end
     hold off
     grid on        
catch Me
    errordlg(['Erro:',Me.message],'Erro','modal')
end


% --- Executes on button press in rbDFP.
function rbDFP_Callback(hObject, eventdata, handles)
% hObject    handle to rbDFP (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Hint: get(hObject,'Value') returns toggle state of rbDFP


% --- Executes on button press in rbDFR.
function rbDFR_Callback(hObject, eventdata, handles)
% hObject    handle to rbDFR (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Hint: get(hObject,'Value') returns toggle state of rbDFR
